
#ifndef RVIZ_PANEL_TUTORIAL__DEMO_PANEL_HPP_
#define RVIZ_PANEL_TUTORIAL__DEMO_PANEL_HPP_

#include <rviz_common/panel.hpp>

namespace rviz_panel_tutorial
{
class DemoPanel
  : public rviz_common::Panel
{
  Q_OBJECT
public:
  explicit DemoPanel(QWidget * parent = nullptr);
  ~DemoPanel() override;
};
}  // namespace rviz_panel_tutorial

#endif  // RVIZ_PANEL_TUTORIAL__DEMO_PANEL_HPP_
