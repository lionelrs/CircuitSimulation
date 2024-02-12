#include <InputComponent.hpp>

nts::InputComponent::InputComponent(nts::Tristate state)
{
    _state = state;
}

nts::InputComponent::~InputComponent()
{
}

void nts::InputComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    return _state;
}

void nts::InputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void nts::InputComponent::setState(nts::Tristate state)
{
    _state = state;
}
