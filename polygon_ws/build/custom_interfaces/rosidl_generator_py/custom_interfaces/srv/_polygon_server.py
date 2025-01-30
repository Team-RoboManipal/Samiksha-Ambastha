# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_interfaces:srv/PolygonServer.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PolygonServer_Request(type):
    """Metaclass of message 'PolygonServer_Request'."""

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
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.PolygonServer_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__polygon_server__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__polygon_server__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__polygon_server__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__polygon_server__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__polygon_server__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PolygonServer_Request(metaclass=Metaclass_PolygonServer_Request):
    """Message class 'PolygonServer_Request'."""

    __slots__ = [
        '_sides',
        '_side_length',
        '_angular_speed',
    ]

    _fields_and_field_types = {
        'sides': 'int32',
        'side_length': 'float',
        'angular_speed': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sides = kwargs.get('sides', int())
        self.side_length = kwargs.get('side_length', float())
        self.angular_speed = kwargs.get('angular_speed', float())

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
        if self.sides != other.sides:
            return False
        if self.side_length != other.side_length:
            return False
        if self.angular_speed != other.angular_speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sides(self):
        """Message field 'sides'."""
        return self._sides

    @sides.setter
    def sides(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sides' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'sides' field must be an integer in [-2147483648, 2147483647]"
        self._sides = value

    @builtins.property
    def side_length(self):
        """Message field 'side_length'."""
        return self._side_length

    @side_length.setter
    def side_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'side_length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'side_length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._side_length = value

    @builtins.property
    def angular_speed(self):
        """Message field 'angular_speed'."""
        return self._angular_speed

    @angular_speed.setter
    def angular_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angular_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'angular_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._angular_speed = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PolygonServer_Response(type):
    """Metaclass of message 'PolygonServer_Response'."""

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
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.PolygonServer_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__polygon_server__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__polygon_server__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__polygon_server__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__polygon_server__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__polygon_server__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PolygonServer_Response(metaclass=Metaclass_PolygonServer_Response):
    """Message class 'PolygonServer_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

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
        if self.message != other.message:
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
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_PolygonServer(type):
    """Metaclass of service 'PolygonServer'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_interfaces.srv.PolygonServer')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__polygon_server

            from custom_interfaces.srv import _polygon_server
            if _polygon_server.Metaclass_PolygonServer_Request._TYPE_SUPPORT is None:
                _polygon_server.Metaclass_PolygonServer_Request.__import_type_support__()
            if _polygon_server.Metaclass_PolygonServer_Response._TYPE_SUPPORT is None:
                _polygon_server.Metaclass_PolygonServer_Response.__import_type_support__()


class PolygonServer(metaclass=Metaclass_PolygonServer):
    from custom_interfaces.srv._polygon_server import PolygonServer_Request as Request
    from custom_interfaces.srv._polygon_server import PolygonServer_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
