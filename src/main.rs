#![no_std]
#![no_main]

use core::panic::PanicInfo;

mod vga_buffer;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    let global_name: &str = "Cobalt";
    let version: &str = "0.0.4";
    let build: i32 = 4;

    println!("Starting {}...\n", global_name);
    println!("{}", global_name);

    println!("Welcome to {}!", global_name);
    println!("Version {} ({}).\n", build, version);
    println!("{} is running on build {}, v{}.\n", global_name, build, version);

    println!("the quick brown fox jumps over the lazy dog\nTHE QUICK BROWN FOX JUMPS OVER THE LAZY DOG\n0123456789\n~`!@#$%^&*()-_+=\\|{{}}[]:;\"'<,>.?/");
    println!("\n[!] There is no CLI to be found [!]");
    println!("> ");

    panic!("This is a testing panic message!");
}

/// This function is called on panic.
#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    println!("\nA critical error has occurred that has forced the\nOS to stop execution as a precaution. Please use\nthe information below for debugging purposes.\n\n{}", info);

    println!("\nThe OS has completely stopped execution.\nTo restart, hold down the power button . . . ");
    loop {}
}
