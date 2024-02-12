#include <ClockComponent.hpp>

nts::ClockComponent::ClockComponent()
{
    _state = Tristate::Undefined;
    _lastTick = 0;
}

nts::ClockComponent::~ClockComponent()
{
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (_lastTick != tick) {
        for (; _lastTick < tick; _lastTick++) {
            _state = (_state == Tristate::True) ? Tristate::False : Tristate::True;
        }
    }
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    return _state;
}

void nts::ClockComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}
