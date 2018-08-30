//
// Created by mkajdak on 30.08.18.
//

#include <gtest/gtest.h>
#include <Windows/MainWindow.hpp>
#include <mocks/IEngineMock.hpp>
#include <mocks/IDectectorsModuleMock.hpp>
#include <mocks/IDetectorMock.hpp>
#include <Buttons/LetterButton.hpp>

using ::testing::_;
using ::testing::Return;
using namespace testing;


class MainWindowTests : public ::testing::Test
{
public:
    MainWindowTests()
    {
        EXPECT_CALL(_engineMock, getDetectorsModule()).
                WillRepeatedly(ReturnRef(_detectorsModuleMock));
        EXPECT_CALL(_detectorsModuleMock,getCollisionDetector()).
                WillOnce(ReturnRef(_detectorMock));
        EXPECT_CALL(_detectorsModuleMock,getEventDetector()).
                WillOnce(ReturnRef(_detectorMock));
        _sut = std::make_unique<MainWindow>(_engineMock);
    }



    eng::det::IDetectorMock _detectorMock;
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
    auto element = eng::Element(button);

    //nrOfElement = element->getElementID();
    _sut->addItemToDraw(element);


    ASSERT_TRUE(_sut->isElement(nrOfElement));
}
