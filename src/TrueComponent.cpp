#include <TrueComponent.hpp>

nts::TrueComponent::TrueComponent()
{
    _inToOut = { { 1, 1 } };
}

nts::TrueComponent::~TrueComponent()
{
}

void nts::TrueComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    return nts::True;
}

void nts::TrueComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}