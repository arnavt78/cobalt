# By Arnav Thorat
# Run this file to optimize your image!
# For Cobalt

Clear-Host

Write-Host "IMAGE OPTIMIZER AND CREATOR"
Write-Host "For use with Cobalt!`n"

# Compile binary
$binaryConfirm = Read-Host -Prompt "Do you want to compile a binary for Cobalt? (Y/N)"

if ($binaryConfirm.ToLower() -eq "y" -or $binaryConfirm.ToLower() -eq "yes") {
  Write-Host "`nMaking binary for Cobalt by running 'cargo bootimage'..."
  cargo bootimage
  Write-Host "Successfully made binary file in 'target\x86_64-cobalt\debug\bootimage-cobalt.bin'!"
}

# Prompt user for binary location just in case
$path = Read-Host "`nPlease enter the path in which the Cobalt binary is located (or press Enter for the default path)"
if ([string]::IsNullOrEmpty($path)) {
  $path = ".\target\x86_64-cobalt\debug\bootimage-cobalt.bin"
  Write-Host "Defaulted to '$path'."
}

# If path does not exist
if (!(Test-Path $path)) {
  Write-Host "ERROR: Path does not exist. Process aborted."
  Exit
}

# Size to add in zeros
$sizeInBytes = 10485760

Write-Host "`nAdding bytes to binary..."

# Create a FileStream object to write to the end of the file
$fileStream = New-Object System.IO.FileStream -ArgumentList $path, "Append"

# Write the required number of zeros to the end of the file
$fileStream.SetLength($fileStream.Length + $sizeInBytes)
$fileStream.Close()

Write-Host "Successfully added bytes to the binary!`n"

$vboxConfirm = Read-Host -Prompt "Do you want to compile a disk image for use in VirtualBox? (Y/N)"
if (!($vboxConfirm.ToLower() -eq "y" -or $vboxConfirm.ToLower() -eq "yes")) {
  Write-Host "All operations have been completed, exiting...`n"
  Exit
}

# Check if VBoxManage is in the PATH
if (!(Get-Command VBoxManage -ErrorAction SilentlyContinue)) {
  # VBoxManage is not in the PATH, so add it
  $env:Path += ";C:\Program Files\Oracle\VirtualBox"
  Write-Host "Added VirtualBox to the PATH."
}

# Prompt user for disk location just in case
$target = Read-Host "Please enter the path in which the VirtualBox disk file should be compiled (or press Enter for the default name)"
if ([string]::IsNullOrEmpty($target)) {
  $target = ".\cobalt.vdi"
  Write-Host "Defaulted to '$target'."
}

if (Test-Path $target) {
  Write-Host "Disk image already exists, deleting..."
  Remove-Item $target
}

Write-Host ""

VBoxManage.exe convertfromraw $path $target --format VDI

$vboxConfirm = Read-Host -Prompt "`nWould you like to create a new VM in VirtualBox for Cobalt? (Y/N)"
if (!($vboxConfirm.ToLower() -eq "y" -or $vboxConfirm.ToLower() -eq "yes")) {
  Write-Host "All operations have been completed, exiting...`n"
  Exit
}

Write-Host "Creating virtual machine 'Cobalt'...`n"

VBoxManage.exe createvm --name "Cobalt" --ostype "Other_64" --register
VBoxManage.exe modifyvm "Cobalt" --memory 32 --cpus 1
VBoxManage.exe storagectl "Cobalt" --name "IDE Controller" --add ide --bootable on
VBoxManage.exe storageattach "Cobalt" --storagectl "IDE Controller" --port 0 --device 0 --type hdd --medium "cobalt.vdi"
VBoxManage.exe modifyvm "Cobalt" --boot1 disk --boot2 none --boot3 none --boot4 none
VBoxManage.exe modifyvm "Cobalt" --vram 12

Write-Host "`nAll operations have been completed, exiting...`n"
Exit
