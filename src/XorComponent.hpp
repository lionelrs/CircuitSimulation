#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class XorComponent : public AComponent {
    public:
        XorComponent();
        ~XorComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}
#endif // !XORCOMPONENT_HPP_