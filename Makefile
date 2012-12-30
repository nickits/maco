CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -m32
LDFLAGS = -Wall -ansi -pedantic -frepo

LIBS= -lcppcms -lbooster -lwtdbo -lwtdbosqlite3

DB_LIB=libmacodb.so

LOCAL_LIBS= -L. -lmacodb

SOURCES_MAIN=main.cpp

SOURCES_DB=datasession.cpp

SOURCES_MODELS=	model/product.cpp \
		model/category.cpp \
		model/collection.cpp \
		model/image.cpp \
		model/video.cpp \
		model/client.cpp \
		model/ownerproduct.cpp \
		model/characteristic.cpp \
		model/featuredproduct.cpp \
		model/productcharacteristic.cpp \
		model/specialoffer.cpp \
		model/company.cpp \
		model/shop.cpp \
		model/sale.cpp \
		model/payment.cpp \
		model/saledetail.cpp

SOURCES_UTILS=	utils/jsonutils.cpp \
		utils/formgenerator.cpp

SOURCES_SERVICES=	services/productsservice.cpp 
					#services/baseservice.cpp
			

SOURCES_PAGES=	pages/basepage.cpp \
		pages/productpage.cpp

SOURCES_APPS=

SOURCES_TPL_CPP_VIEW = view/view.cpp

SOURCES_TPL_VIEW = 	view/admin.tmpl

SOURCES_TPL_CPP_USERVIEW =

SOURCES_TPL_USERVIEW = 

SOURCES=$(SOURCES_MAIN) $(SOURCES_APPS) $(SOURCES_UTILS) $(SOURCES_SERVICES) $(SOURCES_PAGES) $(SOURCES_TPL_CPP_VIEW) $(SOURCES_TPL_CPP_USERVIEW)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=maco

all: clean_tmpl build_local_libs $(DB_LIB) $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ ${LIBS} $(LOCAL_LIBS)


#database
SOURCES_DB_LIB=$(SOURCES_DB) $(SOURCES_MODELS)

OBJECTS_DB=$(SOURCES_DB_LIB:.cpp=.o)

build_local_libs: $(OBJECTS_DB)
	ar rcs $(DB_LIB) $(OBJECTS_DB)

#########

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(SOURCES_TPL_CPP_VIEW): 
	cppcms_tmpl_cc $(SOURCES_TPL_VIEW) -o $(SOURCES_TPL_CPP_VIEW)

$(SOURCES_TPL_CPP_USERVIEW): 
	cppcms_tmpl_cc $(SOURCES_TPL_USERVIEW) -o $(SOURCES_TPL_CPP_USERVIEW)

#%.cpp: %.tmpl
#	cppcms_tmpl_cc $< -o $@

# templates/content.cpp: templates/content.tmpl templates/content.h
# 	cppcms_tmpl_cc templates/content.tmpl -o templates/content.cpp

clean: clean_objects clean_tmpl

clean_objects:
	rm -rf maco *.so *.o ./*.o ./*/*.o ./*/*/*.o cppcms_rundir

clean_tmpl:
	rm -rf ./view/*.cpp ./view/user/*.cpp
