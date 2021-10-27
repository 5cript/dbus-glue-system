#pragma once

#include <dbus-glue/dbus_interface.hpp>

namespace DBus::org::freedesktop::DBus
{
    class ObjectManager
	{
	public:
		virtual ~ObjectManager() = default;

	public: // Methods
		virtual auto GetManagedObjects() -> std::unordered_map <
		    DBusMock::object_path,
		    std::unordered_map <
		        std::string,
		        std::unordered_map <std::string, DBusMock::variant>
		    >
		> = 0;

	public: // Properties

	public: // Signals
		DBusMock::signal <
		    void
		    (
		        DBusMock::object_path,
		        std::unordered_map <std::string, std::unordered_map <std::string, DBusMock::variant>>
		    )
		> InterfacesAdded;
		DBusMock::signal <void(DBusMock::object_path, std::vector <std::string>)> InterfacesRemoved;
	};

	class Introspectable
	{
	public:
		virtual ~Introspectable() = default;

	public: // Methods
		virtual auto Introspect() -> std::string /*xml*/ = 0;

	public: // Properties
	public: // signals
	};
}

DBUS_MOCK_NAMESPACE
(
    (DBus)(org)(freedesktop)(DBus),
    Introspectable,
    DBUS_MOCK_METHODS(Introspect),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_NO_SIGNALS
)

DBUS_MOCK_NAMESPACE
(
    (DBus)(org)(freedesktop)(DBus),
    ObjectManager,
    DBUS_MOCK_METHODS(GetManagedObjects),
    DBUS_MOCK_NO_PROPERTIES,
    DBUS_MOCK_SIGNALS(InterfacesAdded, InterfacesRemoved)
)
