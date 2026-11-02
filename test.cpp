#include <emscripten.h>

// This macro creates a bridge allowing C++ to execute JavaScript code natively
EM_JS(void, print_to_html, (const char* message), {
    // Under the hood, Emscripten passes C++ strings as pointers (numbers). 
    // UTF8ToString converts that pointer back into a standard JavaScript text string.
    let text = UTF8ToString(message);
    
    // Find our HTML element and inject the text
    document.getElementById("output").innerText = text;
});

int main() {
    // This is the message generated deep inside our C++ engine
    print_to_html("Hello World from the C++ Engine via WebAssembly!");
    return 0;
}
