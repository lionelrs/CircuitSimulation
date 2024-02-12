#include <FalseComponent.hpp>

nts::FalseComponent::FalseComponent()
{
    _inToOut = { { 1, 1 } };
}

nts::FalseComponent::~FalseComponent()
{
}

void nts::FalseComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    return nts::False;
}

void nts::FalseComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}