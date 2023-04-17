#![no_std]
#![no_main]

use core::panic::PanicInfo;

mod vga_buffer;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    let global_name: &str = "Cobalt";
    let version: &str = "0.0.3";
    let build: i32 = 3;

    for _ in 0..25 {
        println!("\n");
    }

    println!("{}", global_name);
    
    println!("Version {} ({}).\n", build, version);
    println!("{} is running on build {}, v{}.\n", global_name, build, version);

    println!("[There is no GUI or CLI to be found...]", global_name);

    println!("\n\n\nHold the power button to force shutdown. . . . \n\n");

    loop {}
}

/// This function is called on panic.
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("{}", info);
    loop {}
}
