#![no_std]
#![no_main]

use core::panic::PanicInfo;

mod vga_buffer;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    let global_name: &str = "Cobalt";
    let version: &str = "0.0.2";
    let build: i32 = 2;

    for _ in 0..25 {
        println!("\n");
    }

    println!("Starting {}...\n", global_name);
    
    println!("Welcome to {}!", global_name);
    println!("{} is running on build {}, v{}.\n", global_name, build, version);

    println!("So far, {} has no CLI interface or a GUI.\n\nThere is no more functionality other than loading\nthe kernel and x86_64 bootloader.\n\nIf you are seeing this text, all is well so far!\n\n\nThis is all. You must do a hard shutdown as {}\nhas no safe shutting down functionality yet.\n\n\nThanks for trying out {}!", global_name, global_name, global_name);

    println!("\n\n\nHold down the power button to force shut down {} . . . \n\n", global_name);

    loop {}
}

/// This function is called on panic.
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("{}", info);
    loop {}
}