#![no_std]
#![no_main]

use core::panic::PanicInfo;

mod vga_buffer;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    let global_name: &str = "Cobalt";
    let version: &str = "0.0.3";
    let build: i32 = 3;

    println!("Starting {}...\n", global_name);
    println!("{}", global_name);
    use std::{thread, time};
    thread::sleep(time::Duration::from_secs(2));
    clearscreen::clear().expect("Error - Failure to clear screen.");
    println!("Welcome to {}!", global_name);
    println!("Version {} ({}).\n", build, version);
    println!("{} is running on build {}, v{}.\n", global_name, build, version);

    println!("[!] So far, {} has no CLI or GUI interface. There is\nno more functionality other than loading the kernel\nand x86_64 bootloader. If you are seeing this text,\nall is well so far! This is all. You must do a hard\nshutdown as {} has no safe shutting down functionality\nyet. Thanks for trying out {}!", global_name, global_name, global_name);
    println!("\n[There is no CLI to be found...] [!]");
    println!("> ");

    panic!("This is a testing panic message!");
}

/// This function is called on panic.
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("\nA critical error has occurred that has forced the\nOS to stop execution as a precaution. Please use\nthe information below for debugging purposes.\n\n{}", info);

    println!("\nThe OS has completely stopped execution.\nTo restart, hold down the power button . . . \n");
    loop {}
}
