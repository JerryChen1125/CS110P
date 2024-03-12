#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector *vector_create(void) {
  Vector *vector = malloc(sizeof(Vector));
  if (vector == NULL) {
    perror("Failed to allocate memory for vector");
    exit(EXIT_FAILURE);
  }
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;
  vector->data = malloc(sizeof(double) * vector->capacity);
  if (vector->data == NULL) {
    perror("Failed to allocate memory for vector data");
    exit(EXIT_FAILURE);
  }
  return vector;
}

void vector_push(Vector *vector, double element) {
  if (vector == NULL) {
    fprintf(stderr, "Null pointer passed to vector_push\n");
    return;
  }
  if (vector->size == vector->capacity) {
    double *temp = realloc(vector->data, sizeof(double) * vector->capacity * 2);
    if (temp == NULL) {
      perror("Failed to reallocate memory for vector data");
      exit(EXIT_FAILURE);
    }
    vector->capacity *= 2;
    vector->data = temp;
  }
  vector->data[vector->size++] = element;
}

double vector_get(const Vector *vector, int index) {
  if (vector == NULL) {
    fprintf(stderr, "Null pointer passed to vector_get\n");
    return 0.0;
  }
  if (index < 0 || index >= vector->size) {
    fprintf(stderr, "Index out of bounds in vector_get\n");
    return 0.0;
  }
  return vector->data[index];
}

void vector_free(Vector *vector) {
  if (vector == NULL) {
    fprintf(stderr, "Null pointer passed to vector_free\n");
    return;
  }
  free(vector->data);
  free(vector);
}
