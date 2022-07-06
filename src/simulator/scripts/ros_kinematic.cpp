#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/gazebo.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Pose3.hh>
#include <ignition/math/Quaternion.hh>

namespace gazebo
{
    class KinematicPlugin : public ModelPlugin
    {
    private:
        physics::ModelPtr model;
        physics::LinkPtr base_link;

        sdf::ElementPtr temp;
        event::ConnectionPtr updateConnection;

    public:
        KinematicPlugin() : ModelPlugin()
        {
            printf("Hello World!\n");
        }

        void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
        {
            // Store the pointer to the model
            this->model = _parent;
            this->world = this->model->GetWorld();
            this->mbox = this->world->GetModel("uamv0");
            // this->jointR1_ = this->model->GetJoint("r1");
            this->link1 = this->mbox->GetLink("base_link");

            // Listen to the update event. This event is broadcast every
            // simulation iteration.
            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&KinematicPlugin::OnUpdate, this));
        }

        void OnUpdate()
        {
            // Apply a small linear velocity to the model.
            this->temp->GetElement("pose")->Set(ignition::math::Pose3(ignition::math::Vector3(0, 0, 10), ignition::math::Quaternion(0, 0, 0)));
            this->base_link->UpdateParameters(this->temp);
            // this->model->Set
        }
    };

    GZ_REGISTER_MODEL_PLUGIN(KinematicPlugin)
}