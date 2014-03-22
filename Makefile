DBUSXX_XML2CPP=$(shell which dbusxx-xml2cpp)
DBUS_INTERFACE_SOURCE=org.zedroot.douane.xml
CPP_ADAPTOR_NAME=org_zedroot_douane_adaptor.h
CPP_PROXY_NAME=org_zedroot_douane_proxy.h

all: $(EXEC)
	$(DBUSXX_XML2CPP) $(DBUS_INTERFACE_SOURCE) --adaptor=$(CPP_ADAPTOR_NAME) --proxy=$(CPP_PROXY_NAME)
