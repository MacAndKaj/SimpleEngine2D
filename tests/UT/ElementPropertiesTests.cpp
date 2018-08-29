//
// Created by mkajdak on 29.08.18.
//

#include <gtest/gtest.h>
#include <Helpers/ElementProperties.hpp>

using namespace eng;


class ElementPropertiesTests : public ::testing::Test
{
public:
    void startService()
    {
        _sut = std::make_unique<ElementProperties>(0,0);
    }

    std::unique_ptr<ElementProperties> _sut;
};


TEST_F(ElementPropertiesTests, ElementPropertiesTests_ShouldStoreOnlyCopy_Test)
{
    startService();
    auto element = (*_sut);
    ASSERT_EQ(_sut->getElementID(),1);
    ASSERT_EQ(element.getElementID(),0);
}
