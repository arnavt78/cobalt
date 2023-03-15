def Cobalt_Rattle():
  import os
  import time
  import subprocess
  os.system('color 1f')
  Rattle = True
  def titlebar():
    print("(N)ew","(C)ompile","(O)pen","(E)xit", "(D)ebug")
  def redscreen():
    os.system('color 4f')
    print("An Error has occured.")
    time.sleep(3)
    os.system('color 1f')
    os.system('cls')
    titlebar()
  titlebar()
  time.sleep(1)
  while Rattle == True:
    Rattle_Command = input()
    if Rattle_Command == "E" or Rattle_Command == "Exit":
      Rattle = False
    elif Rattle_Command == "C" or Rattle_Command == "Compile":
      os.system('cls')
      titlebar()
      Rattle_Subcommand = input("PATH: ")
      try:
        with open(Rattle_Subcommand, "r") as filer:
          os.system('cls')
          titlebar()
          exec(filer.read())
      except:
        redscreen()
    elif Rattle_Command == "N" or Rattle_Command == "New":
      Rattle_Temp = True
      os.system('cls')
      titlebar()
      Rattle_Subcommand = input("PATH: ")
      try:
        with open(Rattle_Subcommand, "w") as filer:
          os.system('cls')
          print("Write Code Here...")
          while Rattle_Temp == True:
            me = input()
            if me != "$EXIT":
              filer.write(me)
              filer.write("\n")
            else:
              file.close(filer)
              break
      except:
        redscreen()
    elif Rattle_Command == "O" or Rattle_Command == "Open":
      Rattle_Temp = True
      os.system('cls')
      titlebar()
      Rattle_Subcommand = input("PATH: ")
      try:
        with open(Rattle_Subcommand, 'a') as filer:
          with open(Rattle_Subcommand, 'r') as reader:
            os.system('cls')
            file_read = reader.readlines()
            for i in file_read:
              print(i)
            while Rattle_Temp == True:
              me = input()
              if me != "$EXIT":
                filer.write(me)
                filer.write("\n")
              else:
                filer.close()
                break
      except:
        redscreen()
    elif Rattle_Command == "D" or Rattle_Command == "Debug":
      Rattle_Temp = True
      os.system('cls')
      titlebar()
      Rattle_Subcommand = input("PATH: ")
      rattle_file_dict = {}
      num = 0
      with open(Rattle_Subcommand, 'r') as filer:
        for i in filer.readlines():
          num = num + 1
          strnum = str(num)
          rattle_file_dict[strnum] = i
        while Rattle_Temp == True:
          Rattle_Index = input("EDIT LINE NO. : ")
          if Rattle_Index == "$EXIT":
            filer.close()
            filer.close()
            os.remove(Rattle_Subcommand)
            break
          elif Rattle_Index in rattle_file_dict:
            print("PREVIOUS: ")
            print(Rattle_Index, rattle_file_dict[Rattle_Index])
            rattle_change = input("EDITED: \n")
            rattle_file_dict[Rattle_Index] = rattle_change
      filer = open(Rattle_Subcommand, 'a')
      for i in rattle_file_dict:
        filer.write(rattle_file_dict[i])
        filer.write("\n")

