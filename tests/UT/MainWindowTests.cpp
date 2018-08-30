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

    auto buttonPtr1 = std::unique_ptr<IElement>(new LetterButton);
    auto buttonPtr2 = std::unique_ptr<IElement>(new LetterButton);
    //auto ID1 = buttonPtr

    nrOfElement = buttonPtr1->getElementID();
    unsigned int nrOfElement2 = buttonPtr2->getElementID();
    _sut->addItemToDraw(buttonPtr1);
    _sut->addItemToDraw(buttonPtr2);

    ASSERT_TRUE(_sut->isElement(nrOfElement));
    ASSERT_TRUE(_sut->isElement(nrOfElement2));
}
