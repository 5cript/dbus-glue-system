#include <dbus-mockery/dbus_interface.hpp>

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
		virtual auto RemoveDevice(DBusMock::object_path const& device) -> void = 0;
		virtual auto GetDiscoveryFilters() -> std::string /* filters*/ = 0;

	public: // Properties
		DBusMock::readable <std::string> Address;
		DBusMock::readable <std::string> AddressType;
		DBusMock::readable <std::string> Name;
		DBusMock::read_writeable <std::string> Alias;
		DBusMock::readable <uint32_t> Class;
		DBusMock::read_writeable <bool> Powered;
		DBusMock::read_writeable <bool> Discoverable;
		DBusMock::read_writeable <uint32_t> DiscoverableTimeout;
		DBusMock::read_writeable <bool> Pairable;
		DBusMock::read_writeable <uint32_t> PairableTimeout;
		DBusMock::readable <bool> Discovering;
		DBusMock::readable <std::string> UUIDs;
		DBusMock::readable <std::string> Modalias;

	public: // Signals
	);

	class GattManager
	{
	public:
		virtual ~GattManager() = default;

	public: // Methods
		virtual auto RegisterApplication(DBusMock::object_path const& application, std::unordered_map <std::string, std::string> const& options) -> void = 0;
		virtual auto UnregisterApplication(DBusMock::object_path const& application) -> void = 0;

	public: // Properties

	public: // Signals
	);

	class LEAdvertisingManager
	{
	public:
		virtual ~LEAdvertisingManager() = default;

	public: // Methods
		virtual auto RegisterAdvertisement(DBusMock::object_path const& advertisement, std::unordered_map <std::string, std::string> const& options) -> void = 0;
		virtual auto UnregisterAdvertisement(DBusMock::object_path const& service) -> void = 0;

	public: // Properties
		DBusMock::readable <uint8_t> ActiveInstances;
		DBusMock::readable <uint8_t> SupportedInstances;
		DBusMock::readable <std::string> SupportedIncludes;

	public: // Signals
	);

	class Media
	{
	public:
		virtual ~Media() = default;

	public: // Methods
		virtual auto RegisterEndpoint(DBusMock::object_path const& endpoint, std::unordered_map <std::string, std::string> const& properties) -> void = 0;
		virtual auto UnregisterEndpoint(DBusMock::object_path const& endpoint) -> void = 0;
		virtual auto RegisterPlayer(DBusMock::object_path const& player, std::unordered_map <std::string, std::string> const& properties) -> void = 0;
		virtual auto UnregisterPlayer(DBusMock::object_path const& player) -> void = 0;

	public: // Properties

	public: // Signals
	);

	class NetworkServer
	{
	public:
		virtual ~NetworkServer() = default;

	public: // Methods
		virtual auto Register(std::string const& uuid, std::string const& bridge) -> void = 0;
		virtual auto Unregister(std::string const& uuid) -> void = 0;

	public: // Properties

	public: // Signals
	);

}

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)
    Adapter,
    DBUS_MOCK_METHODS(StartDiscovery, SetDiscoveryFilter, StopDiscovery, RemoveDevice, GetDiscoveryFilters),
    DBUS_MOCK_PROPERTIES(Address, AddressType, Name, Alias, Class, Powered, Discoverable, DiscoverableTimeout, Pairable, PairableTimeout, Discovering, UUIDs, Modalias),
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)
    GattManager,
    DBUS_MOCK_METHODS(RegisterApplication, UnregisterApplication),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)
    LEAdvertisingManager,
    DBUS_MOCK_METHODS(RegisterAdvertisement, UnregisterAdvertisement),
    DBUS_MOCK_PROPERTIES(ActiveInstances, SupportedInstances, SupportedIncludes),
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)
    Media,
    DBUS_MOCK_METHODS(RegisterEndpoint, UnregisterEndpoint, RegisterPlayer, UnregisterPlayer),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)
    NetworkServer,
    DBUS_MOCK_METHODS(Register, Unregister),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)


