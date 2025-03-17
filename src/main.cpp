#include <tuple>

#include <src/panel.hpp>
#include <src/label.hpp>
#include <src/toggle.hpp>
#include <core/App.hpp>

int main() {
    MyApp app;

    using LabeledToggle = Panel<Toggle, Label>;

    LabeledToggle lp{Toggle(), Label()};

    auto components(
        Panel<
            LabeledToggle, 
            Label
        >(lp, Label())
    );

    components.render();

    app.Run();
    return 0;
}
