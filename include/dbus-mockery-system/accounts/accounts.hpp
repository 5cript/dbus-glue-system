#pragma once

#include <dbus-mockery/dbus_interface.hpp>

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
		virtual auto ListCachedUsers() -> DBusMock::object_path /* users*/ = 0;
		virtual auto FindUserById(int64_t id) -> DBusMock::object_path /* user*/ = 0;
		virtual auto FindUserByName(std::string const& name) -> DBusMock::object_path /* user*/ = 0;
		virtual auto CreateUser(std::string const& name, std::string const& fullname, int32_t accountType) -> DBusMock::object_path /* user*/ = 0;
		virtual auto CacheUser(std::string const& name) -> DBusMock::object_path /* user*/ = 0;
		virtual auto UncacheUser(std::string const& name) -> void = 0;
		virtual auto DeleteUser(int64_t id, bool removeFiles) -> void = 0;

	public: // Properties
		DBusMock::readable <std::string> DaemonVersion;
		DBusMock::readable <bool> HasNoUsers;
		DBusMock::readable <bool> HasMultipleUsers;
		DBusMock::readable <DBusMock::object_path> AutomaticLoginUsers;

	public: // Signals
		signal <void(DBusMock::object_path const& /*user*/)> UserAdded;
		signal <void(DBusMock::object_path const& /*user*/)> UserDeleted;
	};
}


DBUS_MOCK_NAMESPACE
(
    (Accounts)(org)(freedesktop)(Accounts),
    Peer,
    DBUS_MOCK_METHODS(Ping, GetMachineId),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (Accounts)(org)(freedesktop)(Accounts),
    Accounts,
    DBUS_MOCK_METHODS(ListCachedUsers, FindUserById, FindUserByName, CreateUser, CacheUser, UncacheUser, DeleteUser),
    DBUS_MOCK_PROPERTIES(DaemonVersion, HasNoUsers, HasMultipleUsers, AutomaticLoginUsers),
    DBUS_MOCK_SIGNALS(UserAdded, UserDeleted)
)

