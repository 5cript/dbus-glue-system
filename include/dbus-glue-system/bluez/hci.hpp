#pragma once

#include <dbus-glue/dbus_interface.hpp>

#include <string>
#include <unordered_map>

namespace BlueZ::org::bluez::hci
{
    class Adapter
	{
	public:
		virtual ~Adapter() = default;

	public: // Methods
		virtual auto StartDiscovery() -> void = 0;
		virtual auto SetDiscoveryFilter(std::unordered_map <std::string, std::string> const& properties) -> void = 0;
		virtual auto StopDiscovery() -> void = 0;
		virtual auto RemoveDevice(DBusGlue::object_path const& device) -> void = 0;
		virtual auto GetDiscoveryFilters() -> std::string /* filters*/ = 0;

	public: // Properties
		DBusGlue::readable <std::string> Address;
		DBusGlue::readable <std::string> AddressType;
		DBusGlue::readable <std::string> Name;
		DBusGlue::read_writeable <std::string> Alias;
		DBusGlue::readable <uint32_t> Class;
		DBusGlue::read_writeable <bool> Powered;
		DBusGlue::read_writeable <bool> Discoverable;
		DBusGlue::read_writeable <uint32_t> DiscoverableTimeout;
		DBusGlue::read_writeable <bool> Pairable;
		DBusGlue::read_writeable <uint32_t> PairableTimeout;
		DBusGlue::readable <bool> Discovering;
		DBusGlue::readable <std::string> UUIDs;
		DBusGlue::readable <std::string> Modalias;

	public: // Signals
	};

	class GattManager
	{
	public:
		virtual ~GattManager() = default;

	public: // Methods
		virtual auto RegisterApplication(DBusGlue::object_path const& application, std::unordered_map <std::string, std::string> const& options) -> void = 0;
		virtual auto UnregisterApplication(DBusGlue::object_path const& application) -> void = 0;

	public: // Properties

	public: // Signals
	};

	class LEAdvertisingManager
	{
	public:
		virtual ~LEAdvertisingManager() = default;

	public: // Methods
		virtual auto RegisterAdvertisement(DBusGlue::object_path const& advertisement, std::unordered_map <std::string, std::string> const& options) -> void = 0;
		virtual auto UnregisterAdvertisement(DBusGlue::object_path const& service) -> void = 0;

	public: // Properties
		DBusGlue::readable <uint8_t> ActiveInstances;
		DBusGlue::readable <uint8_t> SupportedInstances;
		DBusGlue::readable <std::string> SupportedIncludes;

	public: // Signals
	};

	class Media
	{
	public:
		virtual ~Media() = default;

	public: // Methods
		virtual auto RegisterEndpoint(DBusGlue::object_path const& endpoint, std::unordered_map <std::string, std::string> const& properties) -> void = 0;
		virtual auto UnregisterEndpoint(DBusGlue::object_path const& endpoint) -> void = 0;
		virtual auto RegisterPlayer(DBusGlue::object_path const& player, std::unordered_map <std::string, std::string> const& properties) -> void = 0;
		virtual auto UnregisterPlayer(DBusGlue::object_path const& player) -> void = 0;

	public: // Properties

	public: // Signals
	};

	class NetworkServer
	{
	public:
		virtual ~NetworkServer() = default;

	public: // Methods
		virtual auto Register(std::string const& uuid, std::string const& bridge) -> void = 0;
		virtual auto Unregister(std::string const& uuid) -> void = 0;

	public: // Properties

	public: // Signals
	};

}

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci),
    Adapter,
    DBUS_DECLARE_METHODS(StartDiscovery, SetDiscoveryFilter, StopDiscovery, RemoveDevice, GetDiscoveryFilters),
    DBUS_DECLARE_PROPERTIES(Address, AddressType, Name, Alias, Class, Powered, Discoverable, DiscoverableTimeout, Pairable, PairableTimeout, Discovering, UUIDs, Modalias),
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci),
    GattManager,
    DBUS_DECLARE_METHODS(RegisterApplication, UnregisterApplication),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci),
    LEAdvertisingManager,
    DBUS_DECLARE_METHODS(RegisterAdvertisement, UnregisterAdvertisement),
    DBUS_DECLARE_PROPERTIES(ActiveInstances, SupportedInstances, SupportedIncludes),
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci),
    Media,
    DBUS_DECLARE_METHODS(RegisterEndpoint, UnregisterEndpoint, RegisterPlayer, UnregisterPlayer),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci),
    NetworkServer,
    DBUS_DECLARE_METHODS(Register, Unregister),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)


