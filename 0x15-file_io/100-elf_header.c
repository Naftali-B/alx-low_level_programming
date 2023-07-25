#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_magic(unsigned char *e_ident) {
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

void print_class(unsigned char e_ident[EI_NIDENT]) {
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char e_ident[EI_NIDENT]) {
    printf("  Data:                              ");
    switch (e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char e_ident[EI_NIDENT]) {
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

void print_osabi(unsigned char e_ident[EI_NIDENT]) {
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abiversion(unsigned char e_ident[EI_NIDENT]) {
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        dprintf(2, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        dprintf(2, "Error: Cannot open file %s\n", argv[1]);
        return 98;
    }

    Elf32_Ehdr elf_header;
    ssize_t read_status = read(fd, &elf_header, sizeof(elf_header));
    if (read_status != sizeof(elf_header)) {
        dprintf(2, "Error: Cannot read ELF header from %s\n", argv[1]);
        close(fd);
        return 98;
    }

    unsigned char *e_ident = (unsigned char *)&elf_header.e_ident;

    printf("ELF Header:\n");
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_osabi(e_ident);
    print_abiversion(e_ident);

    close(fd);
    return 0;
}
