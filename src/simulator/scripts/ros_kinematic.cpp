#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <gazebo/physics/PhysicsTypes.hh>

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
            //this->model->GetLink("base_link")->SetVelocity(0, 1.0);
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