#pragma once

#include <dbus-glue/dbus_interface.hpp>

#include <string>
#include <cstdint>

// https://docs.pagure.org/SSSD.sssd/design_pages/accounts_service.html
namespace Accounts::org::freedesktop::Accounts
{
  class Peer
	{
	public:
		virtual ~Peer() = default;

	public: // Methods
		virtual auto Ping() -> void = 0;
		virtual auto GetMachineId() -> std::string /* machine_uuid*/ = 0;

	public: // Properties

	public: // Signals
	};

	class Accounts
	{
	public:
		virtual ~Accounts() = default;

	public: // Methods
		virtual auto ListCachedUsers() -> DBusGlue::object_path /* users*/ = 0;
		virtual auto FindUserById(int64_t id) -> DBusGlue::object_path /* user*/ = 0;
		virtual auto FindUserByName(std::string const& name) -> DBusGlue::object_path /* user*/ = 0;
		virtual auto CreateUser(std::string const& name, std::string const& fullname, int32_t accountType) -> DBusGlue::object_path /* user*/ = 0;
		virtual auto CacheUser(std::string const& name) -> DBusGlue::object_path /* user*/ = 0;
		virtual auto UncacheUser(std::string const& name) -> void = 0;
		virtual auto DeleteUser(int64_t id, bool removeFiles) -> void = 0;

	public: // Properties
		DBusGlue::readable <std::string> DaemonVersion;
		DBusGlue::readable <bool> HasNoUsers;
		DBusGlue::readable <bool> HasMultipleUsers;
		DBusGlue::readable <DBusGlue::object_path> AutomaticLoginUsers;

	public: // Signals
		DBusGlue::signal <void(DBusGlue::object_path const& /*user*/)> UserAdded;
		DBusGlue::signal <void(DBusGlue::object_path const& /*user*/)> UserDeleted;
	};
}


DBUS_DECLARE_NAMESPACE
(
    (Accounts)(org)(freedesktop)(Accounts),
    Peer,
    DBUS_DECLARE_METHODS(Ping, GetMachineId),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (Accounts)(org)(freedesktop)(Accounts),
    Accounts,
    DBUS_DECLARE_METHODS(ListCachedUsers, FindUserById, FindUserByName, CreateUser, CacheUser, UncacheUser, DeleteUser),
    DBUS_DECLARE_PROPERTIES(DaemonVersion, HasNoUsers, HasMultipleUsers, AutomaticLoginUsers),
    DBUS_DECLARE_SIGNALS(UserAdded, UserDeleted)
)

