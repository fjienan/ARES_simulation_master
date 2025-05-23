# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ares_comm:srv/Execute.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Execute_Request(type):
    """Metaclass of message 'Execute_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ares_comm')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ares_comm.srv.Execute_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__execute__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__execute__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__execute__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__execute__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__execute__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Execute_Request(metaclass=Metaclass_Execute_Request):
    """Message class 'Execute_Request'."""

    __slots__ = [
        '_func_id',
        '_arg1',
        '_arg2',
        '_arg3',
        '_request_id',
    ]

    _fields_and_field_types = {
        'func_id': 'uint16',
        'arg1': 'uint32',
        'arg2': 'uint32',
        'arg3': 'uint32',
        'request_id': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.func_id = kwargs.get('func_id', int())
        self.arg1 = kwargs.get('arg1', int())
        self.arg2 = kwargs.get('arg2', int())
        self.arg3 = kwargs.get('arg3', int())
        self.request_id = kwargs.get('request_id', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.func_id != other.func_id:
            return False
        if self.arg1 != other.arg1:
            return False
        if self.arg2 != other.arg2:
            return False
        if self.arg3 != other.arg3:
            return False
        if self.request_id != other.request_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def func_id(self):
        """Message field 'func_id'."""
        return self._func_id

    @func_id.setter
    def func_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'func_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'func_id' field must be an unsigned integer in [0, 65535]"
        self._func_id = value

    @builtins.property
    def arg1(self):
        """Message field 'arg1'."""
        return self._arg1

    @arg1.setter
    def arg1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg1' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'arg1' field must be an unsigned integer in [0, 4294967295]"
        self._arg1 = value

    @builtins.property
    def arg2(self):
        """Message field 'arg2'."""
        return self._arg2

    @arg2.setter
    def arg2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'arg2' field must be an unsigned integer in [0, 4294967295]"
        self._arg2 = value

    @builtins.property
    def arg3(self):
        """Message field 'arg3'."""
        return self._arg3

    @arg3.setter
    def arg3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arg3' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'arg3' field must be an unsigned integer in [0, 4294967295]"
        self._arg3 = value

    @builtins.property
    def request_id(self):
        """Message field 'request_id'."""
        return self._request_id

    @request_id.setter
    def request_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'request_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'request_id' field must be an unsigned integer in [0, 255]"
        self._request_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Execute_Response(type):
    """Metaclass of message 'Execute_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ares_comm')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ares_comm.srv.Execute_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__execute__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__execute__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__execute__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__execute__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__execute__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Execute_Response(metaclass=Metaclass_Execute_Response):
    """Message class 'Execute_Response'."""

    __slots__ = [
        '_success',
        '_value',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'value': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.value = kwargs.get('value', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.value != other.value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'value' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'value' field must be an unsigned integer in [0, 4294967295]"
        self._value = value


class Metaclass_Execute(type):
    """Metaclass of service 'Execute'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ares_comm')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ares_comm.srv.Execute')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__execute

            from ares_comm.srv import _execute
            if _execute.Metaclass_Execute_Request._TYPE_SUPPORT is None:
                _execute.Metaclass_Execute_Request.__import_type_support__()
            if _execute.Metaclass_Execute_Response._TYPE_SUPPORT is None:
                _execute.Metaclass_Execute_Response.__import_type_support__()


class Execute(metaclass=Metaclass_Execute):
    from ares_comm.srv._execute import Execute_Request as Request
    from ares_comm.srv._execute import Execute_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
