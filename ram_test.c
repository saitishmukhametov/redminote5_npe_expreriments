#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    long available_memory = pages * page_size;
    size_t memory_to_map = (size_t)(available_memory * 0.9); // 90% of available memory

    // Map the memory
    void* mapped_area = mmap(NULL, memory_to_map, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mapped_area == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Fill the mapped area with dummy data in chunks
    const size_t chunk_size = page_size; // Use the system's page size as the chunk size
    size_t total_filled = 0; // Keep track of the total amount of data filled

    for (size_t offset = 0; offset < memory_to_map; offset += chunk_size) {
        memset((char*)mapped_area + offset, 0xAA, chunk_size);
        total_filled += chunk_size;
        // Print the amount of data filled after each memset operation
        printf("Filled %zu bytes so far\n", total_filled);

    }

    printf("Total memory mapped and filled with dummy data: %zu bytes. Press any key to exit and release memory.\n", total_filled);
    getchar(); // Wait for user input before cleaning up

    // Cleanup
    munmap(mapped_area, memory_to_map);

    return 0;
}
