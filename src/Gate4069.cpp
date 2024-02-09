#include <Gate4069.hpp>

nts::Gate4069::Gate4069()
{
    _inToOut = { { 1, 2 }, { 3, 4 },
        { 5, 6 }, { 9, 8 },
        { 11, 10 }, { 13, 12 } };
    _outToGate = { { 2, 0 }, { 4, 1 }, { 6, 2 }, { 8, 3 }, { 10, 4 }, { 12, 5 } };

    for (size_t i = 0; i < 6; i++) {
        inverters.push_back(std::make_unique<NotComponent>());
    }
}

nts::Gate4069::~Gate4069()
{
}

void nts::Gate4069::simulate(std::size_t tick)
{
}

nts::Tristate nts::Gate4069::compute(std::size_t pin)
{

    if (_outToGate.find(pin) != _outToGate.end()) {
        size_t gateIndex = _outToGate[pin];
        return inverters[gateIndex]->compute(2);
    }
    return Tristate::Undefined;
}

void nts::Gate4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

    if (_inToOut.find(pin) == _inToOut.end()) {
        return;
    }
    size_t gateIndex = _outToGate[_inToOut[pin]];
    inverters[gateIndex]->setLink(1, other, otherPin);
    _links[pin] = std::make_pair(&other, otherPin);
}