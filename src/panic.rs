use core::panic::PanicInfo;
use crate::evm_return;

#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    if let Some(panic_message) = info.payload().downcast_ref::<&str>() {
        evm_return(panic_message.as_ptr(), panic_message.len() as u32);
    } else {
        let panic_message = "panic occurred";
        evm_return(panic_message.as_ptr(), panic_message.len() as u32);
    }
    loop {}
}
