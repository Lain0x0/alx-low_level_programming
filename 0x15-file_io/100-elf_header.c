#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  * print_magic - Print the magic bytes from the ELF header.
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_magic(unsigned char *e_ident)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i < EI_NIDENT - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

/**
 *  * print_class - Print the ELF file class (32-bit or 64-bit).
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
	}
}

/**
 *  * print_data - Print the data encoding (little-endian or big-endian).
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
	}
}

/**
 *  * print_version - Print the ELF version.
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_version(unsigned char *e_ident)
{
	printf("  Version: %d (current)\n", e_ident[EI_VERSION]);
}

/**
 *  * print_osabi - Print the OS/ABI.
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		default:
			printf("<unknown>\n");
	}
}

/**
 *  * print_abi - Print the ABI version.
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 *  * print_type - Print the type of ELF file.
 *   * @e_type: The e_type field in the ELF header.
 *    * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_type(uint16_t e_type, unsigned char *e_ident)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>\n");
	}
}

/**
 *  * print_entry - Print the entry point address.
 *   * @e_entry: The e_entry field in the ELF header.
 *    * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void print_entry(uint64_t e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               0x%lx\n", e_entry);
}

/**
 *  * check_elf - Check if the file is a valid ELF file.
 *   * @e_ident: A pointer to the e_ident field in the ELF header.
*/
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3) {
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 *  * main - Displays the information contained in the
 *   *        ELF header at the start of an ELF file.
 *    * @argc: The number of arguments supplied to the program.
 *     * @argv: An array of pointers to the arguments.
 *      *
 *       * Return: 0 on success.
 *        *
 *         * Description: If the file is not an ELF File or
 *          *              the function fails - exit code 98.
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (98);
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read != sizeof(header))

	{
		dprintf(STDERR_FILENO,
	"Error: Unable to read ELF header from %s\n", argv[1]);
		close(fd);
		return (98);
	}

	check_elf(header.e_ident);
	print_elf_header(&header);

	close(fd);
	return (0);
}

