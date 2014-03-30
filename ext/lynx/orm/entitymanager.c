
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_ORM_EntityManager) {

	ZEPHIR_REGISTER_CLASS(Lynx\\ORM, EntityManager, lynx, orm_entitymanager, lynx_orm_entitymanager_method_entry, 0);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("unitOfWork"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_orm_entitymanager_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_ORM_EntityManager, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

PHP_METHOD(Lynx_ORM_EntityManager, __construct) {

	zval *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	if (!(zephir_is_instance_of(connection, SL("Lynx\\DBAL\\Connection") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Lynx\\DBAL\\Connection'");
		return;
	}
	zephir_update_property_this(this_ptr, SL("connection"), connection TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, lynx_orm_unitofwork_ce);
	zephir_call_method_p1_noret(_0, "__construct", this_ptr);
	zephir_update_property_this(this_ptr, SL("unitOfWork"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lynx_ORM_EntityManager, flush) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);




}

PHP_METHOD(Lynx_ORM_EntityManager, createQueryBuilder) {

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, lynx_orm_querybuilder_ce);
	zephir_call_method_p1_noret(return_value, "__construct", this_ptr);
	RETURN_MM();

}

PHP_METHOD(Lynx_ORM_EntityManager, createQuery) {

	zval *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sql);



	object_init_ex(return_value, lynx_orm_query_ce);
	zephir_call_method_p2_noret(return_value, "__construct", sql, this_ptr);
	RETURN_MM();

}
