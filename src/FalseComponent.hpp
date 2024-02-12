#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class FalseComponent : public AComponent {
    public:
        FalseComponent();
        ~FalseComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}

#endif // FALSECOMPONENT_HPP_
