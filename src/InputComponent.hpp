#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class InputComponent : public AComponent {
    public:
        InputComponent(nts::Tristate state = nts::Tristate::Undefined);
        ~InputComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setState(nts::Tristate state);

    private:
        Tristate _state;
};

}

#endif // !INPUTCOMPONENT_HPP_
