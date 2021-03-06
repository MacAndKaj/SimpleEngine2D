//
// Created by mkajdak on 30.08.18.
//

#include <gtest/gtest.h>
#include <Windows/MainWindow.hpp>
#include <mocks/IEngineMock.hpp>
#include <mocks/IDectectorsModuleMock.hpp>
#include <mocks/IEventDetectorMock.hpp>
#include <mocks/ICollisionDetectorMock.hpp>
#include <Buttons/LetterButton.hpp>

using ::testing::_;
using ::testing::Return;
using namespace testing;


class MainWindowTests : public ::testing::Test
{
public:
protected:
    virtual void SetUp()
    {
        _sut = std::make_unique<MainWindow>(_engineMock);
    }

    MainWindowTests()
    {
        EXPECT_CALL(_engineMock, getDetectorsModule()).
                WillRepeatedly(ReturnRef(_detectorsModuleMock));
        EXPECT_CALL(_detectorsModuleMock,getCollisionDetector()).
                WillOnce(ReturnRef(_collisionDetectorMock));
        EXPECT_CALL(_detectorsModuleMock,getEventDetector()).
                WillOnce(ReturnRef(_eventDetectorMock));
    }



    eng::det::IEventDetectorMock _eventDetectorMock;
    eng::det::ICollisionDetectorMock _collisionDetectorMock;
    eng::det::IDetectorsModuleMock _detectorsModuleMock;
    eng::IEngineMock _engineMock;
    std::unique_ptr<MainWindow> _sut;
};


TEST_F(MainWindowTests, MainWindowTests_ShouldCloseWhileExit_Test)
{

}


TEST_F(MainWindowTests, MainWindowTests_ShouldAddCorrectElements_Test)
{
    unsigned int nrOfElement = 1;
    ASSERT_FALSE(_sut->isElement(nrOfElement));
    auto button = std::make_unique<LetterButton>();
    auto element = std::unique_ptr<IElement>(button.release()->getAsElement());
    std::cout << element->getElementID() << std::endl;
    nrOfElement = element->getElementID();
    _sut->addItemToDraw(element);

    ASSERT_TRUE(_sut->isElement(nrOfElement));
}
