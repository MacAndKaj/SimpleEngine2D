//
// Created by mkajdak on 28.08.18.
//

#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include <Modules/DetectorsModule.hpp>
#include "IEngine.hpp"

namespace eng
{

class Engine : public IEngine
{
public:
    ~Engine() override;
    const det::IDetectorsModule &getDetectorsModule() const override;
//protected:
    Engine();

private:
    std::unique_ptr<det::IDetectorsModule> _detectorsModule;
    Logger _log;

};

} //eng

#endif //ENGINE_ENGINE_HPP
