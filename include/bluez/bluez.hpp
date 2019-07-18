#include <dbus-mockery/dbus_interface.hpp>

#include <string>

namespace BlueZ::org::bluez
{
    class AgentManager
	{
	public:
		virtual ~AgentManager() = default;

	public: // Methods
		virtual auto RegisterAgent(DBusMock::object_path const& agent, std::string const& capability) -> void = 0;
		virtual auto UnregisterAgent(DBusMock::object_path const& agent) -> void = 0;
		virtual auto RequestDefaultAgent(DBusMock::object_path const& agent) -> void = 0;

	public: // Properties

	public: // Signals
	);

	class ProfileManager
	{
	public:
		virtual ~ProfileManager() = default;

	public: // Methods
		virtual auto RegisterProfile(DBusMock::object_path const& profile, std::string const& UUID, std::unordered_map <std::string, std::string> const& options) -> void = 0;
		virtual auto UnregisterProfile(DBusMock::object_path const& profile) -> void = 0;

	public: // Properties

	public: // Signals
	);
}

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)
    AgentManager,
    DBUS_MOCK_METHODS(RegisterAgent, UnregisterAgent, RequestDefaultAgent),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)
    ProfileManager,
    DBUS_MOCK_METHODS(RegisterProfile, UnregisterProfile),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)
