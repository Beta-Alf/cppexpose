

#include <gmock/gmock.h>

#include <cppexpose/reflection/Property.h>
#include <utility>

using namespace cppexpose;

class PropertyTest : public testing::Test
{
public:
    PropertyTest()
    {
    }    
};

TEST_F(PropertyTest, boolSet)
{
    bool callbackVar = false;
    
    auto callback = [&callbackVar](const bool& newVal){
        ASSERT_FALSE(newVal);
        callbackVar = true;
    };
    
    bool value = true;
    
    auto get = [&value] ()
    {
        return value;
    };

    auto set = [&value] (const bool & val)
    {
        value = val;
    };

    auto prop = new Property<bool>("Property", get, set);
    
    prop->valueChanged.connect(callback);
    
    prop->setValue(false);
    
    ASSERT_FALSE(prop->toBool());
    ASSERT_TRUE(callbackVar);
}

TEST_F(PropertyTest, conversionTest_int)
{
    int intVar = 0;
    
    auto intProp = new Property<int>("intProperty", [&](){return intVar;}, [](const int&){});
    
    ASSERT_DOUBLE_EQ(intVar, intProp->toDouble());
    ASSERT_EQ(intVar, intProp->toLongLong());
    ASSERT_EQ(intVar, intProp->toULongLong());
    ASSERT_EQ("0", intProp->toString());
}

TEST_F(PropertyTest, conversionTest_string)
{
    std::string strVar = "3";
    
    auto intProp = new Property<std::string>("stringProperty", [&](){return strVar;}, [](const std::string&){});
    
    ASSERT_DOUBLE_EQ(3, intProp->toDouble());
    ASSERT_EQ(3, intProp->toLongLong());
    ASSERT_EQ(3, intProp->toULongLong());
    ASSERT_EQ("3", intProp->toString());
}