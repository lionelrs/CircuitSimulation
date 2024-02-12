#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class OutputComponent : public AComponent {
    public:
        OutputComponent();
        ~OutputComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}

#endif // !OUTPUTCOMPONENT_HPP_
