
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__org_zedroot_douane_adaptor_h__ADAPTOR_MARSHAL_H
#define __dbusxx__org_zedroot_douane_adaptor_h__ADAPTOR_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace zedroot {

class Douane_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Douane_adaptor()
    : ::DBus::InterfaceAdaptor("org.zedroot.Douane")
    {
        bind_property(DaemonVersion, "s", true, false);
        register_method(Douane_adaptor, GetRules, _GetRules_stub);
        register_method(Douane_adaptor, DeleteRule, _DeleteRule_stub);
        register_method(Douane_adaptor, CreateRule, _CreateRule_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument GetRules_args[] = 
        {
            { "rules", "a(ssb)", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument DeleteRule_args[] = 
        {
            { "rule_id", "s", true },
            { "result", "b", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument CreateRule_args[] = 
        {
            { "rule_id", "s", true },
            { "allow", "b", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument NewActivityToBeValidated_args[] = 
        {
            { "activity", "(ssss)", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod Douane_adaptor_methods[] = 
        {
            { "GetRules", GetRules_args },
            { "DeleteRule", DeleteRule_args },
            { "CreateRule", CreateRule_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Douane_adaptor_signals[] = 
        {
            { "NewActivityToBeValidated", NewActivityToBeValidated_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Douane_adaptor_properties[] = 
        {
            { "DaemonVersion", "s", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Douane_adaptor_interface = 
        {
            "org.zedroot.Douane",
            Douane_adaptor_methods,
            Douane_adaptor_signals,
            Douane_adaptor_properties
        };
        return &Douane_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > DaemonVersion;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual std::vector< ::DBus::Struct< std::string, std::string, bool > > GetRules() = 0;
    virtual bool DeleteRule(const std::string& rule_id) = 0;
    virtual void CreateRule(const std::string& rule_id, const bool& allow) = 0;

public:

    /* signal emitters for this interface
     */
    void NewActivityToBeValidated(const ::DBus::Struct< std::string, std::string, std::string, std::string >& arg1)
    {
        ::DBus::SignalMessage sig("NewActivityToBeValidated");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _GetRules_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector< ::DBus::Struct< std::string, std::string, bool > > argout1 = GetRules();
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _DeleteRule_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        bool argout1 = DeleteRule(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _CreateRule_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        bool argin2; ri >> argin2;
        CreateRule(argin1, argin2);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

} } 
#endif //__dbusxx__org_zedroot_douane_adaptor_h__ADAPTOR_MARSHAL_H
