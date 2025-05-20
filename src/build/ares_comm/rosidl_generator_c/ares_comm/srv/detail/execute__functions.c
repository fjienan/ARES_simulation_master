// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ares_comm:srv/Execute.idl
// generated code does not contain a copyright notice
#include "ares_comm/srv/detail/execute__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ares_comm__srv__Execute_Request__init(ares_comm__srv__Execute_Request * msg)
{
  if (!msg) {
    return false;
  }
  // func_id
  // arg1
  // arg2
  // arg3
  // request_id
  return true;
}

void
ares_comm__srv__Execute_Request__fini(ares_comm__srv__Execute_Request * msg)
{
  if (!msg) {
    return;
  }
  // func_id
  // arg1
  // arg2
  // arg3
  // request_id
}

bool
ares_comm__srv__Execute_Request__are_equal(const ares_comm__srv__Execute_Request * lhs, const ares_comm__srv__Execute_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // func_id
  if (lhs->func_id != rhs->func_id) {
    return false;
  }
  // arg1
  if (lhs->arg1 != rhs->arg1) {
    return false;
  }
  // arg2
  if (lhs->arg2 != rhs->arg2) {
    return false;
  }
  // arg3
  if (lhs->arg3 != rhs->arg3) {
    return false;
  }
  // request_id
  if (lhs->request_id != rhs->request_id) {
    return false;
  }
  return true;
}

bool
ares_comm__srv__Execute_Request__copy(
  const ares_comm__srv__Execute_Request * input,
  ares_comm__srv__Execute_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // func_id
  output->func_id = input->func_id;
  // arg1
  output->arg1 = input->arg1;
  // arg2
  output->arg2 = input->arg2;
  // arg3
  output->arg3 = input->arg3;
  // request_id
  output->request_id = input->request_id;
  return true;
}

ares_comm__srv__Execute_Request *
ares_comm__srv__Execute_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Request * msg = (ares_comm__srv__Execute_Request *)allocator.allocate(sizeof(ares_comm__srv__Execute_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ares_comm__srv__Execute_Request));
  bool success = ares_comm__srv__Execute_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ares_comm__srv__Execute_Request__destroy(ares_comm__srv__Execute_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ares_comm__srv__Execute_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ares_comm__srv__Execute_Request__Sequence__init(ares_comm__srv__Execute_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Request * data = NULL;

  if (size) {
    data = (ares_comm__srv__Execute_Request *)allocator.zero_allocate(size, sizeof(ares_comm__srv__Execute_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ares_comm__srv__Execute_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ares_comm__srv__Execute_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ares_comm__srv__Execute_Request__Sequence__fini(ares_comm__srv__Execute_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ares_comm__srv__Execute_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ares_comm__srv__Execute_Request__Sequence *
ares_comm__srv__Execute_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Request__Sequence * array = (ares_comm__srv__Execute_Request__Sequence *)allocator.allocate(sizeof(ares_comm__srv__Execute_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ares_comm__srv__Execute_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ares_comm__srv__Execute_Request__Sequence__destroy(ares_comm__srv__Execute_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ares_comm__srv__Execute_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ares_comm__srv__Execute_Request__Sequence__are_equal(const ares_comm__srv__Execute_Request__Sequence * lhs, const ares_comm__srv__Execute_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ares_comm__srv__Execute_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ares_comm__srv__Execute_Request__Sequence__copy(
  const ares_comm__srv__Execute_Request__Sequence * input,
  ares_comm__srv__Execute_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ares_comm__srv__Execute_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ares_comm__srv__Execute_Request * data =
      (ares_comm__srv__Execute_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ares_comm__srv__Execute_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ares_comm__srv__Execute_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ares_comm__srv__Execute_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ares_comm__srv__Execute_Response__init(ares_comm__srv__Execute_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // value
  return true;
}

void
ares_comm__srv__Execute_Response__fini(ares_comm__srv__Execute_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // value
}

bool
ares_comm__srv__Execute_Response__are_equal(const ares_comm__srv__Execute_Response * lhs, const ares_comm__srv__Execute_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
ares_comm__srv__Execute_Response__copy(
  const ares_comm__srv__Execute_Response * input,
  ares_comm__srv__Execute_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // value
  output->value = input->value;
  return true;
}

ares_comm__srv__Execute_Response *
ares_comm__srv__Execute_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Response * msg = (ares_comm__srv__Execute_Response *)allocator.allocate(sizeof(ares_comm__srv__Execute_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ares_comm__srv__Execute_Response));
  bool success = ares_comm__srv__Execute_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ares_comm__srv__Execute_Response__destroy(ares_comm__srv__Execute_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ares_comm__srv__Execute_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ares_comm__srv__Execute_Response__Sequence__init(ares_comm__srv__Execute_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Response * data = NULL;

  if (size) {
    data = (ares_comm__srv__Execute_Response *)allocator.zero_allocate(size, sizeof(ares_comm__srv__Execute_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ares_comm__srv__Execute_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ares_comm__srv__Execute_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ares_comm__srv__Execute_Response__Sequence__fini(ares_comm__srv__Execute_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ares_comm__srv__Execute_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ares_comm__srv__Execute_Response__Sequence *
ares_comm__srv__Execute_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__srv__Execute_Response__Sequence * array = (ares_comm__srv__Execute_Response__Sequence *)allocator.allocate(sizeof(ares_comm__srv__Execute_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ares_comm__srv__Execute_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ares_comm__srv__Execute_Response__Sequence__destroy(ares_comm__srv__Execute_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ares_comm__srv__Execute_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ares_comm__srv__Execute_Response__Sequence__are_equal(const ares_comm__srv__Execute_Response__Sequence * lhs, const ares_comm__srv__Execute_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ares_comm__srv__Execute_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ares_comm__srv__Execute_Response__Sequence__copy(
  const ares_comm__srv__Execute_Response__Sequence * input,
  ares_comm__srv__Execute_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ares_comm__srv__Execute_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ares_comm__srv__Execute_Response * data =
      (ares_comm__srv__Execute_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ares_comm__srv__Execute_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ares_comm__srv__Execute_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ares_comm__srv__Execute_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
