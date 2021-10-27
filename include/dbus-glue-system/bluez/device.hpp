#pragma once

#include <dbus-glue/dbus_interface.hpp>

namespace BlueZ::org::bluez::hci::dev
{
    class Device
	{
	public:
		virtual ~Device() = default;

	public: // Methods
		virtual auto Connect() -> void = 0;
		virtual auto CancelPairing() -> void = 0;
		virtual auto ConnectProfile(std::string const& uuid) -> void = 0;
		virtual auto Disconnect() -> void = 0;
		virtual auto DisconnectProfile(std::string const& uuid) ->	void = 0;
		virtual auto Pair() -> void = 0;

	public: // Properties
		DBusMock::readable <std::vector <std::string>> UUIDs;
		DBusMock::read_writeable <bool> Blocked;
		DBusMock::readable <bool> Connected;
		DBusMock::readable <bool> LegacyPairing;
		DBusMock::readable <bool> Paired;
		DBusMock::readable <bool> ServicesResolved;
		DBusMock::read_writeable <bool> Trusted;
		DBusMock::readable <std::unordered_map <std::string, DBusMock::variant>> ServiceData;
		DBusMock::readable <std::unordered_map <uint16_t, DBusMock::variant>> ManufacturerData;
		DBusMock::readable <int16_t> RSSI;
		DBusMock::readable <int16_t> TxPower;
		DBusMock::readable <DBusMock::object_path> Adapter;
		DBusMock::readable <std::string> Address;
		DBusMock::readable <std::string> AddressType;
		DBusMock::read_writeable <std::string> Alias;
		DBusMock::readable <std::string> Icon;
		DBusMock::readable <std::string> Modalias;
		DBusMock::readable <std::string> Name;
		DBusMock::readable <uint16_t> Appearance;
		DBusMock::readable <uint32_t> Class;

	public: // Signals
	};
}

DBUS_MOCK_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)(dev),
    Device,
    DBUS_MOCK_METHODS(Connect, CancelPairing, ConnectProfile, Disconnect, DisconnectProfile, Pair),
    DBUS_MOCK_PROPERTIES(
        UUIDs, Blocked, Connected, LegacyPairing, Paired, ServicesResolved, Trusted, ServiceData,
        ManufacturerData, RSSI, TxPower, Adapter, Address, AddressType, Alias, Icon, Modalias, Name, Appearance, Class
    ),
    DBUS_MOCK_NO_SIGNALS
)
