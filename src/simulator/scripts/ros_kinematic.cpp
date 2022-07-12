#include "ros_kinematic.hpp"

PluginNode::PluginNode() : rclcpp::Node("gz_plugin",
                                        rclcpp::NodeOptions()
                                            .allow_undeclared_parameters(true)
                                            .automatically_declare_parameters_from_overrides(true))
{

    RCLCPP_INFO(get_logger(), "Initializing gz_plugin node.\n");

    clk_subscriber_ = this->create_subscription<rosgraph_msgs::msg::Clock>("clock",
                                                                           10,
                                                                           std::bind(&PluginNode::clk_update, this, std::placeholders::_1));
    pose_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseStamped>("uam/pose",
                                                                                  10,
                                                                                  std::bind(&PluginNode::pose_update, this, std::placeholders::_1));
    twst_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>("uam/twist",
                                                                            10,
                                                                            std::bind(&PluginNode::twist_update, this, std::placeholders::_1));
}

void PluginNode::clk_update(const rosgraph_msgs::msg::Clock::SharedPtr time) const
{
    current::time = time->clock.sec;
}

void PluginNode::pose_update(const geometry_msgs::msg::PoseStamped::SharedPtr pose) const
{
    current::pose[0] = pose->pose.position.x;
    current::pose[1] = pose->pose.position.y;
    current::pose[2] = pose->pose.position.z;

    current::orientation[0] = pose->pose.orientation.w;
    current::orientation[1] = pose->pose.orientation.x;
    current::orientation[2] = pose->pose.orientation.y;
    current::orientation[3] = pose->pose.orientation.z;
}

void PluginNode::twist_update(const geometry_msgs::msg::Twist::SharedPtr twst) const
{
    ;
}

float g = 0.0;

namespace gazebo
{
    class ModelPush : public ModelPlugin
    {
    public:
        void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
        {
            // Store the pointer to the model
            this->model = _parent;

            // Listen to the update event. This event is broadcast every
            // simulation iteration.
            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&ModelPush::OnUpdate, this));
        }

        // Called by the world update start event
    public:
        void OnUpdate()
        {
            g++;
            // Apply a small linear velocity to the model.
            // this->model->SetLinearVel(ignition::math::Vector3d(.3, 0, 0));
            this->model->GetJoint("prop1")->SetVelocity(0, 10);
            this->model->GetJoint("prop2")->SetVelocity(0, 10);
            this->model->GetJoint("prop3")->SetVelocity(0, 10);
            this->model->GetJoint("prop4")->SetVelocity(0, 10);
            this->model->GetJoint("inter")->SetVelocity(0, 0);

            this->model->GetJoint("manip_base")->SetVelocity(0, 0);
            this->model->GetJoint("end")->SetVelocity(0, 0);
            
            this->model->GetLink("base_link")->SetLinearVel({0, 0, 0.1});
            this->model->GetLink("base_link")->SetAngularVel({0, 0, 0});
            // this->model->GetLink("base_link")->SetVelocity(0, 1.0);

            // BASE LINK
            current::pose_here = this->model->GetLink("base_link")->WorldInertialPose();
            current::pose_here - current::pose;
        }

        // Pointer to the model
    private:
        physics::ModelPtr model;

        // Pointer to the update event connection
    private:
        event::ConnectionPtr updateConnection;
    };

    // Register this plugin with the simulator
    GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}