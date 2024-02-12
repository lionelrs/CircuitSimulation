#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class TrueComponent : public AComponent {
    public:
        TrueComponent();
        ~TrueComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}

#endif // !TRUECOMPONENT_HPP_
