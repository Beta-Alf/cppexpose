
#pragma once


#include <cppexpose/reflection/Property.h>

#include <cppexpose/reflection/PropertyGroup.h>


namespace cppexpose
{


template <typename T>
template <typename... Args>
Property<T>::Property(PropertyGroup * parent, const std::string & name, Args&&... args)
: StoredValue<T, AbstractProperty>(std::forward<Args>(args)...)
{
    this->initProperty(parent, name);
}

template <typename T>
Property<T>::~Property()
{
}

template <typename T>
bool Property<T>::isGroup() const
{
    return false;
}

template <typename T>
void Property<T>::onValueChanged(const T & value)
{
    this->valueChanged(value);
}


} // namespace cppexpose
