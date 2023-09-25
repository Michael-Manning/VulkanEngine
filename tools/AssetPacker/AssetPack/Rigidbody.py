# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class Rigidbody(object):
    __slots__ = ['_tab']

    @classmethod
    def SizeOf(cls):
        return 52

    # Rigidbody
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Rigidbody
    def EntityId(self): return self._tab.Get(flatbuffers.number_types.Uint32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(0))
    # Rigidbody
    def Collider(self, obj):
        obj.Init(self._tab.Bytes, self._tab.Pos + 4)
        return obj

    # Rigidbody
    def LinearDamping(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(20))
    # Rigidbody
    def AngularDamping(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(24))
    # Rigidbody
    def FixedRotation(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(28))
    # Rigidbody
    def Bullet(self): return self._tab.Get(flatbuffers.number_types.BoolFlags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(32))
    # Rigidbody
    def GravityScale(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(36))
    # Rigidbody
    def Friction(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(40))
    # Rigidbody
    def Density(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(44))
    # Rigidbody
    def Restitution(self): return self._tab.Get(flatbuffers.number_types.Float32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(48))

def CreateRigidbody(builder, entityId, collider_type, collider_radius, collider_scale_x, collider_scale_y, linearDamping, angularDamping, fixedRotation, bullet, gravityScale, friction, density, restitution):
    builder.Prep(4, 52)
    builder.PrependFloat32(restitution)
    builder.PrependFloat32(density)
    builder.PrependFloat32(friction)
    builder.PrependFloat32(gravityScale)
    builder.Pad(3)
    builder.PrependBool(bullet)
    builder.PrependFloat32(fixedRotation)
    builder.PrependFloat32(angularDamping)
    builder.PrependFloat32(linearDamping)
    builder.Prep(4, 16)
    builder.Prep(4, 8)
    builder.PrependFloat32(collider_scale_y)
    builder.PrependFloat32(collider_scale_x)
    builder.PrependFloat32(collider_radius)
    builder.PrependInt32(collider_type)
    builder.PrependUint32(entityId)
    return builder.Offset()