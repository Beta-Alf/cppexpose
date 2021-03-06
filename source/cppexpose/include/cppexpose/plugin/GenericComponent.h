
#pragma once


#include <cppexpose/plugin/AbstractGenericComponent.h>


namespace cppexpose
{


/**
*  @brief
*    Represents a generic component of a specific type
*
*  @see
*    AbstractGenericComponent
*/
template <typename Type, typename BaseType>
class GenericComponent : public AbstractGenericComponent<BaseType>
{
public:
    /**
    *  @brief
    *    Constructor
    */
    GenericComponent();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~GenericComponent();

    // Virtual AbstractGenericComponent<BaseType> interface
    virtual BaseType * createInstance() const override;
};


} // namespace cppexpose


#include <cppexpose/plugin/GenericComponent.inl>
