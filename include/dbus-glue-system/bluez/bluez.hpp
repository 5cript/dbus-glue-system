#pragma once

#include <dbus-glue/dbus_interface.hpp>

#include <string>

namespace BlueZ::org::bluez
{
  class AgentManager
	{
	public:
		virtual ~AgentManager() = default;

	public: // Methods
		virtual auto RegisterAgent(DBusGlue::object_path const& agent, std::string const& capability) -> void = 0;
		virtual auto UnregisterAgent(DBusGlue::object_path const& agent) -> void = 0;
		virtual auto RequestDefaultAgent(DBusGlue::object_path const& agent) -> void = 0;

	public: // Properties

	public: // Signals
	};

	class ProfileManager
	{
	public:
		virtual ~ProfileManager() = default;

	public: // Methods
		virtual auto RegisterProfile(DBusGlue::object_path const& profile, std::string const& UUID, std::unordered_map <std::string, DBusGlue::variant> const& options) -> void = 0;
		virtual auto UnregisterProfile(DBusGlue::object_path const& profile) -> void = 0;

	public: // Properties

	public: // Signals
	};
}

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez),
    AgentManager,
    DBUS_DECLARE_METHODS(RegisterAgent, UnregisterAgent, RequestDefaultAgent),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez),
    ProfileManager,
    DBUS_DECLARE_METHODS(RegisterProfile, UnregisterProfile),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)
