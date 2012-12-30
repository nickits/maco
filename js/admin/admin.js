window.addEvent('domready', function(){
	var dropMenu = new MooDropMenu($('nav'),{ 
        onOpen: function(el){ 
            el.fade('in') 
        }, 
        onClose: function(el){ 
            el.fade('out'); 
        }, 
        onInitialize: function(el){ 
            el.fade('hide').set('tween',{duration:1000}); 
        } 
    }); 
	var grid = new DataGrid({entity: entity});
    grid.load();  

});

var DataGrid = new Class({
	initialize: function(params){
		this.entity = params.entity;
	},
	load: function(){
		
		var jsonRequest = new Request.JSON({url: 'grid/' + this.entity, onSuccess: function(gridconf){

			this.form = new EditForm({entity: this.entity, grid: this});

			this.datagrid = new omniGrid('admin_grid', {
				columnModel: gridconf.columns,
				buttons : [
					{name: 'Add', bclass: 'add', onclick : this.gridAddClick.bind(this)},
					{name: 'Edit', bclass: 'edit', onclick : this.gridEditClick.bind(this)},
					{name: 'Delete', bclass: 'delete', onclick : this.gridDeleteClick.bind(this)}
				],
				url: "griddata/" + this.entity,
				perPageOptions: [10, 20, 50, 100, 200],
				perPage: 20,
				page: 1,
				pagination: true,
				serverSort: true,
				showHeader: true,
				alternaterows: true,
				showHeader: true,
				sortHeader: false,
				resizeColumns: true,
				multipleSelection: true,
				// uncomment this if you want accordion behavior for every row
				/*
				accordion: true,
				accordionRenderer: accordionFunction,
				autoSectionToggle: false,
				*/
				//width: gridconf.width,
				//height: gridconf.height
			});
/*			this.datagrid.addEvent('click', function(evt){
				var str = 'row: ' + evt.row + ' indices: ' + evt.indices;
				str += ' id: ' + evt.target.getDataByRow(evt.row).id;
				alert(str);
			});*/
		}.bind(this)}).get();

		var jsonFRequest = new Request.JSON({url: 'filterinit/' + this.entity , onSuccess: function(form){
			this.formFilter = new Element('form', {
			id:"myFilter",
			action:"filterpost/" + this.entity,
			method:"post",
			class: "hidden"
			});
			
			this.formFilterButton = new Element('span', {
				id:"myFilter",
				text:"filter",
				class: "filterButton"
			});
			this.formFilterButton.addEvent("click", function(){
						if(this.formFilter.hasClass("show")){
							this.formFilter.removeClass("show");
						}
						else{
							this.formFilter.addClass("show");
						}
				}.bind(this));
			
			$('admin_filter').adopt(this.formFilterButton);
			$('admin_filter').adopt([this.formFilter, new Element('div#myResult')]);
			var fieldset = this.formFilter;
			if(form.fieldset){
			var legend = new Element("legend", {text: form.fieldset});
			fieldset = new Element("fieldset");
			fieldset.inject(this.formFilter);
			legend.inject(fieldset);
			}
			
			var ul = new Element('ul');
			ul.inject(fieldset);
			Array.each(form.data, function(element, index){
				var li = new Element('li');
				li.inject(this);
				if(element.tag == "group"){
				Array.each(element.params, function(element, index){
				var el = new Element(element.tag, element.params);
				el.inject(this);
				}, li);
				}
				else{
				var el = new Element(element.tag, element.params);
				el.inject(li);
				}  
			}, ul); 
			
			this.bContainer = new Element("div");
			var liContainer = new Element("li");
			ul.adopt([new Element("li"), liContainer]);
			this.bContainer.inject(liContainer);
			Array.each(form.buttons, function(element, index){
				var el;
				if(element.tag == "filterButton"){
					el = new Element("input", element.params);
					el.addEvent('click', function(evt){
						var formParams = {};
						Array.each(this.formFilter.elements, function(element, index){
							if(element.name){
								formParams[element.name] = element.value;
							}
						}, formParams);
						this.datagrid.loadData(null, formParams)
					}.bind(this));
				}
				else{
					el = new Element(element.tag, element.params);
				}
				el.inject(this.bContainer);
			}, this); 
			
			// Labels over the inputs.
			this.formFilter.getElements('[type=text], textarea').each(function(el){
				new OverText(el);
			});

			// Validation.
			new Form.Validator.Inline(this.formFilter);

			// Ajax (integrates with the validator).
	/*		new Form.Request(this.formFilter, myResult, {
				requestOptions: {
					'spinnerTarget': this.formFilter
				},
				extraData: { // This is just to make this example work.
					'html': 'Form sent.'
				}
			});    */
			$('delete_ok').addEvent('click', function(){
				new Request({
					url: 'delete/' + this.entity + '/' + this.datagrid.options.data[this.datagrid.selected[0]].id, 
					onSuccess: function(result){
						this.datagrid.loadData();
						this.closeDeletePopup();
					}.bind(this)
				}).send();		
			}.bind(this));
			$('delete_cancel').addEvent('click', function(){
				this.closeDeletePopup();
			}.bind(this));
		}.bind(this)}).get();	
	},
	gridAddClick: function(button, grid){
		this.form.execute(0);
	},
	gridEditClick: function(button, grid){
		if(grid.selected.length > 0){
			this.form.execute(grid.options.data[grid.selected[0]].id);
		}
	},
	gridDeleteClick: function(button, grid){
		if(grid.selected.length > 0){
			$('modal_frame').addClass('show');
			$('confirm_delete').addClass('show');
		}		
	},
	closeDeletePopup: function(){
		$('modal_frame').removeClass('show');
		$('confirm_delete').removeClass('show');
	}
});