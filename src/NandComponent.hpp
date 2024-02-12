#ifndef NANDCOMPONENT_HPP_
#define NANDCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class NandComponent : public AComponent {
    public:
        NandComponent();
        ~NandComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}
#endif // !NANDCOMPONENT_HPP_