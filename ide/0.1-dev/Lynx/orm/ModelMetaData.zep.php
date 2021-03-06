<?php

namespace Lynx\ORM;

class ModelMetaData
{

    protected $classname;

    protected $tablename;

    protected $properties;

    protected $columns;


	public function getClassname() {}


	public function getTablename() {}

    /**
     * @param mixed $classname 
     */
	public function __construct($classname) {}


	public function getObject() {}


	public function getColumns() {}


	public function getProperties() {}

    /**
     * @param string $key 
     */
	public function getColumn($key) {}

    /**
     * 
     * Get <Column> by entity's field name
     *
     * @param mixed $field 
     */
	public function getColumnNameByFieldName($field) {}

    /**
     * @param string $key 
     */
	public function getProperty($key) {}


	public function getPrimaryKey() {}


	public function getPrimaryFieldName() {}

    /**
     * @param mixed $field 
     */
	public function getFieldNameByColumn($field) {}

}
