// 
// pq_struct.h
// 
// Your Name: Kara Wolley

#include <string>
#ifndef pq_struct_h
#define pq_struct_h

// initialize the heap structure
struct pq {
    std::string text; // data type string
    float priority; // define priority
    pq* next;   // init next pointer
};

#endif
