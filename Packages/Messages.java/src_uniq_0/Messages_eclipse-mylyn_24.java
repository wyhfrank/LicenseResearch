/*******************************************************************************
 * Copyright (c) 2011 Tasktop Technologies and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Tasktop Technologies - initial API and implementation
 *******************************************************************************/

package org.eclipse.mylyn.commons.ui.team;

import org.eclipse.osgi.util.NLS;

class Messages extends NLS {

	private static final String BUNDLE_NAME = "org.eclipse.mylyn.commons.ui.team.messages"; //$NON-NLS-1$

	public static String RepositoryLocationPart_Anonymous;

	public static String RepositoryLocationPart_Change_Settings;

	public static String RepositoryLocationPart_Disconnected;

	public static String RepositoryLocationPart_Enable_HTTP_Authentication;

	public static String RepositoryLocationPart_Enable_Proxy_Authentication;

	public static String RepositoryLocationPart_Enter_a_valid_server_url;

	public static String RepositoryLocationPart_HTTP_Authentication;

	public static String RepositoryLocationPart_Label;

	public static String RepositoryLocationPart_Password;

	public static String RepositoryLocationPart_Proxy_Host;

	public static String RepositoryLocationPart_Proxy_Port;

	public static String RepositoryLocationPart_Proxy_Server_Configuration;

	public static String RepositoryLocationPart_Repository_is_valid;

	public static String RepositoryLocationPart_Save_Password;

	public static String RepositoryLocationPart_Server;

	public static String RepositoryLocationPart_Unexpected_error_during_repository_validation;

	public static String RepositoryLocationPart_Use_global_Network_Connections_preferences;

	public static String RepositoryLocationPart_User;

	public static String RepositoryLocationPart_Validating_repository;
	
	static {
		// initialize resource bundle
		NLS.initializeMessages(BUNDLE_NAME, Messages.class);
	}

	private Messages() {
	}
	
}
