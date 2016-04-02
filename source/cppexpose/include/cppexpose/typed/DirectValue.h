
#pragma once


#include <cppexpose/typed/TypeSelector.h>


namespace cppexpose
{


/**
*  @brief
*    Typed value (read/write) that is stored directly
*/
template <typename T>
class DirectValue : public TypeSelector<T>::Type
{
public:
    /**
    *  @brief
    *    Constructor
    */
    DirectValue();

    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] value
    *    Initial value
    */
    DirectValue(const T & value);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~DirectValue();

    // Virtual AbstractTyped interface
    virtual AbstractTyped * clone() const override;

    // Virtual Typed<T> interface
    virtual T value() const override;
    virtual void setValue(const T & value) override;


protected:
    T m_value;  ///< The stored value
};


/**
*  @brief
*    Typed value (read-only) that is stored directly
*/
template <typename T>
class DirectValue<const T> : public DirectValue<T>
{
public:
    /**
    *  @brief
    *    Constructor
    */
    DirectValue();

    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] value
    *    Initial value
    */
    DirectValue(const T & value);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~DirectValue();

    // Virtual AbstractTyped interface
    virtual AbstractTyped * clone() const override;
    virtual bool isReadOnly() const override;

    // Virtual Typed<T> interface
    virtual void setValue(const T & value) override;
};


} // namespace cppexpose


#include <cppexpose/typed/DirectValue.hpp>
